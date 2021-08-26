import React from 'react'

export const TravelScreen = (props) => {
	return (
		<div className='character-stats'>
			<label>Hit Points:</label>
			<div data-value="0.4" className='rpgui-progress red' data-rpguitype='progress'>
				<div className='rpgui-progress-track'>
					<div className='rpgui-progress-fill red' style={{ width: '40%' }}></div>
				</div>
				<div className='rpgui-progress-left-edge'></div>
				<div className='rpgui-progress-right-edge'></div>
			</div>
		</div>
	)
}