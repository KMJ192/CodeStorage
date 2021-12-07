import productList from "../productList";
import productInfo from "../productInfo";
import shoppingBack from "../shoppingBack";

import { PageTypes } from "./types";

// export class RoutePath {
//   data: string[];

//   constructor() {
//     this.data = [];
//   }

//   setList(id: string) {
//     this.data.push(id);
//   }
// }

function router(mainContainer: Element) {
  const routePath: string = location.pathname;
  if (routePath === "/") {
    productList(mainContainer);
  } else if (routePath.indexOf("/products/") === 0) {
    productInfo(mainContainer);
  } else {
    shoppingBack();
  }
}

window.onhashchange = () => {
  console.log(1);
};

export default router;
