import React from "react";
import './navi.css';
//import Popup from 'react-popup';

class Navibar extends React.Component {
	constructor(){
		super();
		this.login_button=this.login_button.bind(this);
	}
	login_button = () => {
		if (this.props.user === null)
			return "I am not logged in";
		else if(this.props.user.is_admin === 1)
			return "I am an admin";
		else if(this.props.user.is_admin === 0)
			return "I am an just a user";
	}
	render(props) {
		// const logged_in = this.props.logged_in;
		// const user = this.user;


		return (
			<div id ="navi_bar" className="navi_bar">
				<p>Welcome to the E-Guide</p>
				{this.login_button()}
				<ul>
					<li><a href={"./home"}>Home</a></li>

				</ul>
			</div>
		);		
	}
}

export default Navibar;
