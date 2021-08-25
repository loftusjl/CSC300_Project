import React, { useState } from 'react'
import { BrowserRouter as Router, Route, Switch } from 'react-router-dom'
import SelectMenu from './pages/SelectMenu'
import Layout from './Layout'

function App() {

  return (
    <div className="App">
      <Layout>
        <Router>
          <Switch>
            <Route exact path='/' component={SelectMenu} />

          </Switch>
        </Router>
      </Layout>
    </div>
  )
}

export default App
