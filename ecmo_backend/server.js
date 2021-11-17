
const path = require("path");
const express = require("express");
const app = express();
const port = process.env.PORT || 5000;
app.use(express.json()); //used to parse JSON bodies
var router = express.Router();

// Middleware
const cors = require('cors');

// API request handlers
const scenarioHandler = require('./routes/scenario');
const textbookHandler = require('./routes/textbook');

app.use(cors());
app.use('/api/scenarios', scenarioHandler);
app.use('/api/textbook', textbookHandler);

// //GET request USER
// const getUser=  (req,res) => {
//     res.send({user: 'Micah'}) ;
// };
// app.get("/api/user",getUser);

// //POST request heart rate
// app.post("/input",(req,res) => {
//     const {a,b} = req.body;
//     res.send({hr: parseInt(a), bp: parseInt(b)});
// });

app.listen(port, () => {
    console.log(`ECMO backend server is running at http://localhost:${port}`);
});


//app.use(express.urlencoded()); //parse URL-encoded bodies
