const ajax = new XMLHttpRequest();

/**
 *
 * @param {'GET'} method
 * @param {string} url
 * @returns
 */
function api(method, url) {
  if (!ajax) {
    console.error("Do not crate ajax instance ");
    return;
  }
  ajax.open(method, url, false);
  ajax.setRequestHeader("Access-Control-Allow-Origin", "*");
  ajax.send();

  const res = ajax.response;
  console.log(res);
  return res;
}

export default api;
