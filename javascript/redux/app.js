import { createStore } from "./redux.js";
import {
  increase,
  decrease,
  increaseFive,
  reset,
  setCounter,
  asyncIncrease,
  asyncRequest,
  asyncResponse,
  reducer,
  ASYNC_INCREASE,
} from "./reducer.js";
import { logger } from "./logger.js";

const aysncRouter = (jobs) => (store) => (next) => (action) => {
  const matchJob = Object.entries(jobs).find(([type]) => action.type === type);
  // console.log(matchJob, action);
  if (matchJob) {
    matchJob[1](store, action);
  } else {
    next(action);
  }
};

const asyncJobs = {
  [ASYNC_INCREASE]: (store, action) => {
    store.dispatch(asyncRequest());
    setTimeout(() => {
      store.dispatch(increase(20));
      store.dispatch(asyncResponse());
    }, 3000);
  },
};

const store = createStore(reducer, [aysncRouter(asyncJobs)]);

const counterDisplay = document.querySelector("#counter");
const loadingMessage = document.querySelector("#loading");
const btnIncrease = document.querySelector("#btn-increase");
const btnAsyncIncrease = document.querySelector("#btn-async-increase");
const btnDecrease = document.querySelector("#btn-decrease");
const btnReset = document.querySelector("#btn-reset");

store.subscribe(function () {
  const { count, request } = store.getState();
  loadingMessage.style.visibility = request ? "visible" : "hidden";
  counterDisplay.textContent = count;
});

const dispatch = store.dispatch;

dispatch(setCounter(0));

btnReset.addEventListener("click", () => {
  dispatch(setCounter(0));
});

btnIncrease.addEventListener("click", () => {
  dispatch(increase());
});

btnAsyncIncrease.addEventListener("click", () => {
  dispatch(asyncIncrease({ url: "/async-increase" }));
});

btnDecrease.addEventListener("click", () => {
  dispatch(decrease());
});
