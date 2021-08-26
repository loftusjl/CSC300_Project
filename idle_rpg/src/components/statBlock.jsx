import React from 'react'

export const StatBlock = ({ label, decimalValue, percentValue, color }) => {
	return (
		<div className='character-stat'>
			<label>{label}:</label>
			<div data-value={decimalValue} className={`rpgui-progress ${color}`} data-rpguitype='progress'>
				<div className='rpgui-progress-track'>
					<div className={`rpgui-progress-fill ${color}`} style={{ width: percentValue }}></div>
				</div>
				<div className='rpgui-progress-left-edge'></div>
				<div className='rpgui-progress-right-edge'></div>
			</div>
		</div>
	)
}