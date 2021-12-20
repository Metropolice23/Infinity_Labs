from configparser import ConfigParser
from datetime import datetime
import pytz
from flask import Flask, render_template, request
from requests import get
import calendar

days = ('one', 'two', 'three', 'four', 'five', 'six', 'seven')
app = Flask('weatherApp')


@app.route('/')
def home():
    return render_template('home.html')


@app.route('/result', methods=['POST'])
def render_result():
    place = request.form['loc']
    api_key = get_api()

    coordinates = get_coordinates_results(place, api_key)
    lat = coordinates['coord']['lat']
    lon = coordinates['coord']['lon']
    location = coordinates['name']
    short_country = coordinates['sys']['country']
    country = pytz.country_names[short_country]
    data = get_weather_results(lat, lon, api_key)

    complete = {'name': location, 'country': country}
    for i in range(7):
        daily = {}
        daily['day'] = '{0:.2f}'.format(data['daily'][i]['temp']['day'])
        # if data['daily'][i]['temp']['day'] > 25:
        #     daily['day']['color'] = 'red'
        # elif data['daily'][i]['temp']['day'] < 10:
        #     daily['day']['color'] = 'blue'
        # else:
        #     daily['day']['color'] = 'black'
        daily['night'] = '{0:.2f}'.format(data['daily'][i]['temp']['night'])
        # if data['daily'][i]['temp']['day'] > 25:
        #     daily['night']['color'] = 'red'
        # elif data['daily'][i]['temp']['day'] < 10:
        #     daily['night']['color'] = 'blue'
        # else:
        #     daily['night']['color'] = 'black'
        daily['weather'] = data['daily'][i]['weather'][0]['main']
        daily['humidity'] = data['daily'][i]['humidity']
        timestamp = data['daily'][i]['dt']
        daily["weekday"] = calendar.day_name[datetime.fromtimestamp(timestamp).weekday()]
        daily['date'] = datetime.fromtimestamp(timestamp).isoformat().split('T')[0]

        complete[i] = daily
        print(complete)
    return render_template('result.html', complete=complete)


def get_api():
    config = ConfigParser()
    config.read('config.ini')
    return config['weather']['api']


def get_coordinates_results(place, api_key):
    api_url = "https://api.openweathermap.org/" \
              "data/2.5/weather?q={}&appid={}".format(place, api_key)
    coord_req = get(api_url)
    return coord_req.json()


def get_weather_results(lat, lon, api_key):
    api_url = "https://api.openweathermap.org/" \
              "data/2.5/onecall?lat={}&lon={}&units=metric&exclude=current,minutely,alerts,hourly&appid={}".format(lat, lon, api_key)
    weather_req = get(api_url)
    return weather_req.json()


if __name__ == "__main__":
    app.run()
