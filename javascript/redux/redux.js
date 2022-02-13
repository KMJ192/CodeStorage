// redux
export function createStore(reducer, middlewares = []) {
  let state = {};
  let handlers = [];

  function dispatch(action) {
    state = reducer(state, action);
    handlers.forEach((handler) => handler());
  }

  function getState() {
    return state;
  }

  function subscribe(handler) {
    handlers.push(handler);
  }

  const store = {
    getState,
    subscribe,
    dispatch,
  };

  const ms = Array.from(middlewares).reverse();
  let lastDispatch = dispatch;
  ms.forEach((middleware) => {
    lastDispatch = middleware(store)(lastDispatch);
  });

  store.dispatch = lastDispatch;

  return store;
}

// actionCreator
export const actionCreator = (actionType) => (payload) => ({
  type: actionType,
  payload,
});
