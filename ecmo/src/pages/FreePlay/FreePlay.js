import React from "react";
import {Header, Footer, Card} from "../../components";
import Unity, { UnityContext } from "react-unity-webgl";
import "./FreePlay.scss";

// This is the context that Unity will use to communicate with the React app.
const unityContext = new UnityContext({
  // The url's of the Unity WebGL runtime, these paths are public and should be
  // accessible from the internet and relative to the index.html.
  loaderUrl: "unitybuild/myunityapp.loader.js",
  dataUrl: "unitybuild/myunityapp.data",
  frameworkUrl: "unitybuild/myunityapp.framework.js",
  codeUrl: "unitybuild/myunityapp.wasm",
});

export default function FreePlay() {  
  return (
    <div className="freeplay">
      <Header title="ECMO Unity Freeplay"/>
      <div className="freeplay__card-container">
        <Card  bgColour="#0A2A5A" cardPadding="60px" childComponent={<Unity unityContext={unityContext} height="680px" width="900px"/>}/>
      </div>
      <Footer/>
    </div>
  );
}