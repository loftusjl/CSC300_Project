import React from 'react'
import { BrowserRouter as Router, Route, Switch } from 'react-router-dom'
import SelectMenu from './pages/SelectMenu'
import { TravelScreen } from './pages/TravelScreen'
import Layout from './Layout'
import { CombatScreen } from './pages/CombatScreen'

function App() {

  return (
    <div className="App">
      <Layout>
        <Router>
          <Switch>
            <Route exact path='/Travel' component={TravelScreen} />
            <Route exact path='/Combat' component={CombatScreen} />
            <Route exact path='/' component={SelectMenu} />
          </Switch>
        </Router>
      </Layout>
    </div>
  )
}

export default App
