import React from '@react';
import App from '@src/App';

const { render, useState, useEffect } = React();

// render(App, document.getElementById('App'));

function Test() {
  const [count, setCount] = useState(1);
  const [count2, setCount2] = useState(1);
  const [mount, setMount] = useState(false);

  useEffect(() => {
    if (!mount) {
      setMount(true);
      setCount(count + 1);
    }
  }, [mount, count]);

  useEffect(() => {
    if (!mount) {
      setCount2(count2 + 1);
    }
  }, [count2, mount]);

  return `
    <div>${count}</div>
  `;
}

render(Test, document.getElementById('App'));
