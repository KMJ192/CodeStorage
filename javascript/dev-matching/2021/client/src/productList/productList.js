import api from "../api";
import { productListUrl } from "../urls";

function productList() {
  api("GET", productListUrl);
  // const prodList = await api("GET", productListUrl).then((item) => {
  //   console.log(item);
  //   return item;
  // });
}

export default productList;
