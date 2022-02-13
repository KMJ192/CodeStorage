import { actionCreator } from "./redux.js";

export const COUNT_REDUX = "count";
// action-type
export const INCREASE = "increase";
export const DECREASE = "decrease";
export const INCREASE_FIVE = "in_fv";
export const RESET = "reset";
export const SET_COUNTER = "setCounter";
export const ASYNC_INCREASE = "asycnIncrease";
export const ASYNC_REQUEST = "asyncRequest";
export const ASYNC_RESPONSE = "asyncResponse";

// actions
export const increase = actionCreator(INCREASE);
export const decrease = actionCreator(DECREASE);
export const increaseFive = actionCreator(INCREASE_FIVE);
export const reset = actionCreator(RESET);
export const setCounter = actionCreator(SET_COUNTER);
export const asyncIncrease = actionCreator(ASYNC_INCREASE);
export const asyncRequest = actionCreator(ASYNC_REQUEST);
export const asyncResponse = actionCreator(ASYNC_RESPONSE);

// reducer
const InitializeState = {
  message: "app store",
  request: false,
  count: 0,
};

export function reducer(state = InitializeState, action) {
  switch (action.type) {
    case INCREASE:
      if (action.payload) {
        return {
          ...state,
          count: state.count + action.payload,
        };
      } else {
        return {
          ...state,
          count: state.count + 1,
        };
      }
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
    case SET_COUNTER:
      return {
        ...state,
        count: action.payload,
      };
    case ASYNC_REQUEST:
      return {
        ...state,
        request: true,
      };
    case ASYNC_RESPONSE:
      return {
        ...state,
        request: false,
      };
    default:
      return { ...state };
  }
}
