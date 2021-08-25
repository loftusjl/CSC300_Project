import React from 'react';

const Layout = (props) => {

	return (
		<div className="rpgui-content">
			<div className='inner rpgui-container framed'>
				<h1 className='title'>Idle RPG!</h1>

				<div className='wrapper'>{props.children}</div>
			</div>
		</div>
	)
}

export default Layout;