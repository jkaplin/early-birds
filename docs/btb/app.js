// Application Dependencies
// ===============================================================================

/* Import Application Dependencies */
var path = require('path');
var express = require('express');
const session = require('express-session');
const mongoose = require('mongoose');
const passport = require('passport');
const bodyParser = require('body-parser');
const expressValidator = require('express-validator');
const flash = require('connect-flash');



// Passport Config
require('./config/passport')(passport);


/* Create/Import Routes */
var indexRouter = require('./routes/index');


// Initialize Application Server
// ===============================================================================
var app = express();

// Add MiddleWare

// Passport middleware
app.use(passport.initialize());
app.use(passport.session());

// ===============================================================================

// Set Path to Static HTML Pages
app.use(express.static(path.join(__dirname, 'public/html/')));

// Request Body Parsers
app.use(express.json());
app.use(express.urlencoded({ extended: false }));

// Use 'express-session' to Automatically Create Cookies
var sess_options = {
	secret: 'whippersnapper' + Math.floor((Math.random() * 1000000000000) + 1),
	cookie: { secure: true, maxAge: 60000 },
	resave: false,
	saveUninitialized: true,
};
app.use(session(sess_options));


// Set Created Routes
app.use('/', indexRouter);

var promise = mongoose.connect('mongodb://localhost:27017/btb');

promise.then(() => console.log('MongoDB Connected'))
.catch(err => console.log(err));

let db = mongoose.connection;

// Check for DB errors
db.on('error', function(err){
  console.log(err);
});

// Bring in Models
let Restraunt = require('./models/restraunt');

// Load View Engine
app.set('views', path.join(__dirname, 'views'));
app.set('view engine', 'pug');

// Body Parser Middleware
// parse application/x-www-form-urlencoded
app.use(bodyParser.urlencoded({ extended: false }));
// parse application/json
app.use(bodyParser.json());

// Set Public Folder
app.use(express.static(path.join(__dirname, 'public')));

// Express Session Middleware
app.use(session({
  secret: 'keyboard cat',
  resave: true,
  saveUninitialized: true
}));

// Express Messages Middleware
app.use(require('connect-flash')());
app.use(function (req, res, next) {
  res.locals.messages = require('express-messages')(req, res);
  next();
});

// Express Validator Middleware
app.use(expressValidator({
  errorFormatter: function(param, msg, value) {
      var namespace = param.split('.')
      , root    = namespace.shift()
      , formParam = root;

    while(namespace.length) {
      formParam += '[' + namespace.shift() + ']';
    }
    return {
      param : formParam,
      msg   : msg,
      value : value
    };
  }
}));

// Passport Config
require('./config/passport')(passport);
// Passport Middleware
app.use(passport.initialize());
app.use(passport.session());

app.get('*', function(req, res, next){
  res.locals.user = req.user || null;
  next();
});

// Home Route
app.get('/', function(req, res){
  Restraunt.find({}, function(err, restraunts){
    if(err){
      console.log(err);
    } else {
      res.render('index', {
        title:'Restraunts',
        restraunts: restraunts
      });
    }
  });
});

// Route Files
let restraunts = require('./routes/restraunts');
let users = require('./routes/users');
app.use('/restraunts', restraunts);
app.use('/users', users);

// Export
// ===============================================================================

module.exports = app;
