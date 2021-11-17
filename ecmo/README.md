# Front-end

This project was bootstrapped with [Create React App](https://github.com/facebook/create-react-app).

## Dependencies

- [React](https://reactjs.org/)
- [Pulse Physiology Engine](https://pulse.kitware.com/)
- [DynamoDB](https://aws.amazon.com/dynamodb/)
- [Node.js](https://nodejs.org/en/) & [ExpressJS](https://expressjs.com/)

## System Structure

Currently the folder structure for the system follows:

```
/ecmo [frontend]
/ecmo_backend [backend]
/Testing [QA testing]
```

## Folder Structure

```
/public
    /unitybuild [used to include unity model into the application]
/src
    /components [contains different reusable UI components]
    /pages [contains different pages in the application]
    /routes [page routing]
    /shared [used for application-wide assests, styling and etc.]
```

## Installation

To get the development environment running on the frontend follow these steps:

```
cd ecmo/src
npm install
```

## Running the app

```
cd ecmo/src
npm start
```

Runs the app in the development mode.<br />
Open [http://localhost:3000](http://localhost:3000) to view it in the browser.

The page will reload if you make edits.<br />
You will also see any lint errors in the console.

## Deployment

```
npm run build
```

Builds the app for production to the `build` folder.<br />
It correctly bundles React in production mode and optimizes the build for the best performance.

The build is minified and the filenames include the hashes.<br />
Your app is ready to be deployed!

See the section about [deployment](https://facebook.github.io/create-react-app/docs/deployment) for more information.

<!-- ## Known Issues -->

<!-- ## Troubleshooting FAQ -->

## Features Planned

- Implementation of additional modules of Pulse Physiology Engine (Currently only have pump functionality)
- Allow option to convert scenario training into E-assessment and E-Vigilation platform
- User authentication: Admin, student and e-invigilator
- Add content to textbook and scenarios
- Integrate pulse physiology engine on the free play model

<!-- ## Internal links -->
