import React, { useState } from 'react';
import { SiteContext } from './context/SiteContext';

const Layout = (props) => {
	const [characterName, setCharacterName] = useState('');

	return (
		<SiteContext.Provider value={{ characterName, setCharacterName }}>
			<div className="rpgui-content">
				<div className='inner rpgui-container framed'>
					<h1 className='title'>Idle RPG!</h1>
					<h3>The text-based RPG of the future is now!</h3>

					<div className='wrapper'>{props.children}</div>
				</div>
			</div>
		</SiteContext.Provider>
	)
}

export default Layout;