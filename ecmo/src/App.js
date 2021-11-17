
import React, { Component } from "react";
// import Routes from "./Routes";

import {BrowserRouter as Router, Route, Switch} from "react-router-dom"
import { 

  /** AUTH */
  Login,
  Landing,

  /** TEXTBOOK */
  ChapterSelect, ConfigurablePageA,

  /** TRAINING - SCENARIO */
  ScenarioSelectPage, ScenarioDescriptionPage, ScenarioExplanationPage, AccessInsufficiencyScenario,

  /** FREEPLAY - MODEL */
  FreePlay,

  /** DEV PAGE */
  TestPage,

} from "./pages";

/**  for use after implemented authentication
import PublicRoute from "./routes/PublicRoute";
import AuthRoute from "./routes/AuthRoute";
*/

import { PATH } from "./shared/constant";



class App extends Component {
  render() {
    return (
      <Router>
        <div className="App">
          <Switch>
            <Route path="/" exact component={Login} />
            <Route path={PATH.LANDING} component={(props) => <Landing {...props} />} /> {/** should use AuthRoute */}


            {/** TEXTBOOK */}

            <Route path={PATH.TEXTBOOK.CHAPTERSELECT} component={(props) => <ChapterSelect {...props} />} /> 
            <Route path={`${PATH.TEXTBOOK.PAGE1}/:pageNum`} component={(props) => <ConfigurablePageA {...props} />} /> 

            {/** TRAINING - SCENARIO */}
            <Route path={PATH.TRAINING.ScenarioSelectPage} component={(props) => <ScenarioSelectPage {...props} />} /> 
            <Route path={PATH.TRAINING.ScenarioDescriptionPage} component={(props) => <ScenarioDescriptionPage {...props} />} /> 
            <Route path={PATH.TRAINING.ScenarioExplanationPage} component={(props) => <ScenarioExplanationPage {...props} />} /> 
            <Route path={PATH.TRAINING.AccessInsufficiencyScenario} component={(props) => <AccessInsufficiencyScenario {...props} />} /> 






            <Route path={PATH.FREEPLAY} component={(props) => <FreePlay {...props} />} />

            <Route path={PATH.TEST} component={(props) => <TestPage {...props} />} />
     
          </Switch>
        </div>
      </Router>
    );
  }
}

export default App;