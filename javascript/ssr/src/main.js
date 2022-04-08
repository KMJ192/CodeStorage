export const render = (RootComponent) => `
  <!doctype html>
  <html lang="ko">
  <head>
    <meta charset="UTF-8">
    <title>Server Side Rendering</title>
  </head>
  <body>
    <div id="app">${RootComponent}</div>
  </body>
  </html>
`;

render();
