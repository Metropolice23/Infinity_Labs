import flask

app = flask.Flask('weatherApp')


@app.route('/')
def home():
    return "home"


if __name__ == "__main__":
    app.run()