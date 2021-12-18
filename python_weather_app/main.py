import configparser

from flask import Flask, render_template, request

app = Flask('weatherApp')


@app.route('/')
def home():
    return render_template('home.html')


@app.route('/', methods=['GET'])
def index():
    location = request.form['loc']

    api = get_api()


def get_api():
    config = configparser.ConfigParser()
    config.read('config.ini')
    return config['openweathermap']['api']


if __name__ == "__main__":
    app.run(debug=True)
