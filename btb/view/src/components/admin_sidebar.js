import React from 'react';
import './sidebar.css';


const SideBar = (props) => {
        return (
            <div className="wrapper">
            <aside className="main_sidebar">
                <ul>
                    <li onClick={() => props.change_page('edit')}>Edit information</li>
                    <li onClick={() => props.change_page('comment')}>Comments</li>
                </ul>
            </aside>
        </div> 
        )
    }

    export default SideBar;
