import React from "./react";
import App from "./src/App";
import "./style.css";

const root = document.getElementById("App");
if (root !== null) root.innerHTML = App();

function Test() {
  const [count, setCount] = React.useState<number>(0);

  React.useEffect(() => {
    console.log(count);
  }, [count]);

  return {
    render: () => {
      console.log("rendering");
    },
    click: () => setCount(count + 1),
  };
}
let app = React.render(Test);
app.click();
app.render();
app.click();
app.render();
app.click();
app.render();

// const render = new (Render() as any)();
