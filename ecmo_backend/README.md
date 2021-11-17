## Foreword
Express is built initially for the backend of this project. However, due to the high usage of AWS services, the React Web App is integrated to AWS API Gateway instead of Express. Hence, it is for the next team to decide whether to keep the Express (skeleton for the Express routes are done) and extent it or use the AWS services as the backend.


## Installation
Before installing, [download and install Node.js](https://nodejs.org/en/download/) . Node.js 0.10 or higher is required.

```sh
npm install express
```
## Quick Start

Install Dependencies:
```sh
npm install
```

Start the Server:

```sh
npm start
```

## Example

Create a route for backend:
```sh
const express = require('express')
const app = express()

app.get('/', function (req, res) {
  res.send('Hello World')
})

app.listen(3000)
```

## Documentation
Visit the [wiki](https://github.com/expressjs/express/wiki)

## License
[MIT](https://github.com/expressjs/express/blob/master/LICENSE)
