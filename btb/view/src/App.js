import React, { Component } from 'react';
import './App.css';
import Login from './components/login.js';
import LandingPage from './components/main.js';
import Admin from './components/admin.js'
import { BrowserRouter, Route } from 'react-router-dom';

class App extends Component {

	constructor(){
    super();
    this.state = {
	  coords: {
			lat: 37.529659,
      lng: -122.040237
	  },
      user: null
    }
		this.get_coords = this.get_coords.bind(this);
  }


     get_coords = () => {
    if (navigator.geolocation)
    {
      navigator.geolocation.getCurrentPosition((position) => {
        this.setState({
          coords: {
            lat: position.coords.latitude,
            lng: position.coords.longitude
          }
        });
    });

	}}

	componentDidMount() {
		this.get_coords();
	}

  render() {
	return (
	<div className="App">
  <BrowserRouter>
    <Route path="/home" render={(props) => <LandingPage coords={this.state.coords} user={this.state.user} get_coords={this.get_coords}/>} />
    <Route path="/login" render={(props) => <Login />} />
    <Route path="/admin" render={(props) => <Admin />} />
    </BrowserRouter>
	</div>
	);
  }
}

export default App;
