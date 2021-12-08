import ProductList from "../productList";
import ProductInfo from "../productInfo";
import ShoppingBack from "../shoppingBack";

import { PageTypes } from "./types";

import { ShoppingBackParam } from "../shoppingBack/types";
import { ProductInfoParam } from "../productInfo/types";
import { ProductListParam } from "../productList/types";

interface Routes {
  path: string;
  view: (mainContainer: Element) => void;
}

const initRoutes: Routes[] = [
  {
    path: "/",
    view: (mainContainer: Element) => {
      const param: ProductListParam = {
        mainContainer,
      };
      const productList = new ProductList(param);
      productList.render();
    },
  },
  {
    path: "/products",
    view: () => {
      console.log("products");
    },
  },
  {
    path: "/cart",
    view: () => {
      console.log("cart");
    },
  },
];

function router() {
  const mainContainer: Element = document.getElementsByClassName("App")[0];
  const { pathname } = location;

  const routing = initRoutes.map((page: Routes) => {
    return {
      route: page,
      isMatch: pathname === page.path,
    };
  });

  let match = routing.find((match) => match.isMatch);
  match?.route.view(mainContainer);
}

// document.addEventListener("DOMContentLoaded", () => {
//   router();
// });
// https://www.youtube.com/watch?v=6BozpmSjk-Y

export default router;
