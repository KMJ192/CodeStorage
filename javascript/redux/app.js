// redux
export function createStore(reducer) {
  let state;
  let handlers = [];

  function dispatch(action) {
    state = reducer(state, action);
    handlers.forEach((handler) => handler());
  }

  function subscribe(handler) {
    handlers.push(handler);
  }

  function getState() {
    console.log(handlers);
    return state;
  }

  return {
    getState,
    subscribe,
    dispatch,
  };
}

// actionCreator
export const actionCreator = (type) => (payload) => ({ type, payload });

// reducer
const InitializeState = { count: 0 };

export function reducer(state = InitializeState, action) {
  switch (action.type) {
    case INCREASE:
      return {
        ...state,
        count: state.count + 1,
      };

    case DECREASE:
      return {
        ...state,
        count: state.count - 1,
      };
    case INCREASE_FIVE:
      return {
        ...state,
        count: state.count + action.payload,
      };
    case RESET:
      return {
        ...state,
        count: 0,
      };
    default:
      return { ...state };
  }
}

// action-type
export const INCREASE = "increase";
export const DECREASE = "decrease";
export const INCREASE_FIVE = "in_fv";
export const RESET = "reset";

// actions
export const increase = actionCreator(INCREASE);
export const decrease = actionCreator(DECREASE);
export const increaseFive = actionCreator(INCREASE_FIVE);
export const reset = actionCreator(RESET);

// import createStre, actions
const store = createStore(reducer);

store.subscribe(function () {
  console.log(store.getState());
});

store.dispatch(increase());
store.dispatch(increase());
store.dispatch(decrease());
store.dispatch(increaseFive(5));
store.dispatch(reset());
