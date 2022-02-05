function createStore() {
  let state;
  let handlers = [];

  function send() {
    state = worker(state);
    handlers.forEach((handler) => handler());
  }

  function subscribe(handler) {
    handlers.push(handler);
  }

  function getState() {
    return state;
  }

  return {
    getState,
    subscribe,
    send,
  };
}

function worker(state = { count: 0 }) {
  return {
    ...state,
    count: state.count + 1,
  };
}

const store = createStore(worker);

store.subscribe(function () {
  console.log(store.getState());
});

store.send();
store.send();
store.send();
