import React, { useContext } from 'react';
import { SiteContext } from '../context/SiteContext';

export const AutoPilot = (props) => {
	const { toggleAutopilot, setToggleAutopilot } = useContext(SiteContext)
	return (
		<div
			className='autopilot'
			onClick={() => setToggleAutopilot(!toggleAutopilot)}
		>
			<input
				checked={toggleAutopilot}
				onChange={() => setToggleAutopilot(!toggleAutopilot)}
				className='rpgui-checkbox golden'
				type='checkbox'
				data-rpguitype='checkbox'
			/>
			<label>Auto-Pilot</label>
		</div>
	)
}