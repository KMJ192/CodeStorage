// redux
export function createStore(reducer) {
  let state = {};
  let reducers = {};
  let handlers = [];
  for (const [key, value] of Object.entries(reducer)) {
    reducer = {
      ...reducer,
      [key]: value,
    };
    value({ count: 0 }, "increase");
  }
  // Object.keys(reducer).forEach((key) => {
  //   reducer = {
  //     ...reducer,
  //     [key]: reducer[key],
  //   };
  //   const test = reducer[key];
  //   console.log(test());

  // });
  console.log(state);

  function dispatch(key, action) {
    // state = {
    //   [key]: reducers[key](state, action),
    // };
    // state[key] = reducers[key](state, action);
    // handlers.forEach((handler) => handler());
  }

  function subscribe(handler) {
    handlers.push(handler);
  }

  function getState() {
    // console.log(handlers);
    return state;
  }

  return {
    getState,
    subscribe,
    dispatch,
  };
}

// actionCreator
export const actionCreator = (reduxType, actionType) => (payload) => ({
  [reduxType]: { type: actionType, payload },
});

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

export function reducer2(state = InitializeState, action) {
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

// redux type
export const COUNT_REDUX = "count";
// action-type
export const INCREASE = "increase";
export const DECREASE = "decrease";
export const INCREASE_FIVE = "in_fv";
export const RESET = "reset";

// actions
export const increase = actionCreator(COUNT_REDUX, INCREASE);
export const decrease = actionCreator(COUNT_REDUX, DECREASE);
export const increaseFive = actionCreator(COUNT_REDUX, INCREASE_FIVE);
export const reset = actionCreator(COUNT_REDUX, RESET);

// import createStre, actions
const store = createStore({ count: reducer, count1: reducer2 });

store.subscribe(function () {
  console.log(store.getState());
});

store.dispatch(COUNT_REDUX, increase());
store.dispatch(COUNT_REDUX, increase());
store.dispatch(COUNT_REDUX, decrease());
store.dispatch(COUNT_REDUX, increaseFive(5));
store.dispatch(COUNT_REDUX, reset());
