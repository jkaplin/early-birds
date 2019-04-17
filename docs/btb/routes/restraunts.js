const express = require('express');
const router = express.Router();

// Restraunt Model
let Article = require('../models/restraunt');
// User Model
let User = require('../models/user');

// Add Route
router.get('/add', ensureAuthenticated, function(req, res){
  res.render('add_article', {
    title:'Add Restraunt'
  });
});

// Add Submit POST Route
router.post('/add', function(req, res){
  req.checkBody('name','Title is required').notEmpty();
  req.checkBody('address','Body is required').notEmpty();

  // Get Errors
  let errors = req.validationErrors();

  if(errors){
    res.render('add_restraunt', {
      title:'Add Restraunt',
      errors:errors
    });
  } else {
    let restraunt = new Restraunt();
    restraunt.title = req.body.title;
    restraunt.author = req.user._id;
    restraunt.body = req.body.body;

    restraunt.save(function(err){
      if(err){
        console.log(err);
        return;
      } else {
        req.flash('success','Restraunt Added');
        res.redirect('/');
      }
    });
  }
});

// Load Edit Form
router.get('/edit/:id', ensureAuthenticated, function(req, res){
  Restraunt.findById(req.params.id, function(err, restraunt){
    if(restraunt.owner != req.user._id){
      req.flash('danger', 'Not Authorized');
      res.redirect('/');
    }
    res.render('edit_restraunt', {
      title:'Edit Restraunt',
      restraunt:restraunt
    });
  });
});

// Update Submit POST Route
router.post('/edit/:id', function(req, res){
  let restraunt = {};
  restraunt.name = req.body.title;
  restraunt.owner = req.body.owner;
  restraunt.body = req.body.body;

  let query = {_id:req.params.id}

  Article.update(query, article, function(err){
    if(err){
      console.log(err);
      return;
    } else {
      req.flash('success', 'Article Updated');
      res.redirect('/');
    }
  });
});

// Delete Restraunt
router.delete('/:id', function(req, res){
  if(!req.user._id){
    res.status(500).send();
  }

  let query = {_id:req.params.id}

  Restraunt.findById(req.params.id, function(err, article){
    if(restraunt.owner != req.user._id){
      res.status(500).send();
    } else {
      Restraunt.remove(query, function(err){
        if(err){
          console.log(err);
        }
        res.send('Success');
      });
    }
  });
});

// Get Single Restraunt
router.get('/:id', function(req, res){
  Restraunt.findById(req.params.id, function(err, restraunt){
    User.findById(article.author, function(err, user){
      res.render('restraunt', {
        restraunt:restraunt,
        owner: user.name
      });
    });
  });
});

// Access Control
function ensureAuthenticated(req, res, next){
  if(req.isAuthenticated()){
    return next();
  } else {
    req.flash('danger', 'Please login');
    res.redirect('/users/login');
  }
}

module.exports = router;
