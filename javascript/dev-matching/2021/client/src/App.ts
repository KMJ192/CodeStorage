import router from "./router";

function App() {
  const mainContainer: Element = document.getElementsByClassName("App")[0];
  router(mainContainer);
}

export default App;
