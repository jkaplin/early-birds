let mongoose = require('mongoose');

// Restraunt Schema
let restrauntSchema = mongoose.Schema({
  name:{
    type: String,
    required: true
  },
  address:{
    type: String,
    required: true
  },
  body:{
    type: String,
    required: true
  }
});

let Restraunt = module.exports = mongoose.model('Restraunt', restrauntSchema);
