import React from 'react';
import SideBar from './admin_sidebar.js';

class Admin extends React.Component {
    constructor() {
        super();
        this.state = {
            view: 'edit'
        }
		this.change_page = this.change_page.bind(this);
    }

	change_page = (page) => {
		this.setState({
			view: page
		})
	}
    render() {
        return (
			<>
        	    <SideBar change_page={this.change_page}/>
				<div>hi</div>
			</>
        )
    }
}

export default Admin;
