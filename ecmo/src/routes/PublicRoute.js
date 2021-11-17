import React from 'react';
import { Route } from 'react-router-dom';

/**  for use after implemented authentication
import { Route, Redirect } from 'react-router-dom'; 
import { PATH } from '../shared/constant';
*/

const PublicRoute = ({ component: Component, ...rest }) => {
  // if (authenticated) {
  //   return (
  //     <Redirect
  //       to={PATH.WhatIsEcmo}
  //     />
  //   );
  // }
  return (
    <Route
      {...rest}
      render={(props) => (
        <Component {...props} />
      )}
    />
  );
};

export default PublicRoute;
