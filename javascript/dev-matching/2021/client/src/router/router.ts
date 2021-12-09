import ProductList from "../productList";
import ProductInfo from "../productInfo";
import ShoppingBack from "../shoppingBack";

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
    path: "products",
    view: (mainContainer: Element) => {
      const param: ProductInfoParam = {
        mainContainer,
      };
      const prodInfo = new ProductInfo(param);
      prodInfo.render();
    },
  },
  {
    path: "cart",
    view: (mainContainer: Element) => {
      const param: ShoppingBackParam = {
        mainContainer,
      };
      const shoppingBack = new ShoppingBack(param);
      shoppingBack.render();
    },
  },
];

export const navigateTo = (url: string) => {
  history.pushState(null, "", url);
  router();
};

async function router() {
  const mainContainer: Element = document.getElementsByClassName("App")[0];
  const { pathname } = location;

  const routing = initRoutes.map((page: Routes) => {
    if (page.path === "/") {
      return {
        route: page,
        isMatch: pathname === page.path,
      };
    }
    return {
      route: page,
      isMatch: pathname.indexOf(page.path) >= 0,
    };
  });

  console.log(routing);
  let match = routing.find((match) => match.isMatch);

  if (!match) {
    match = {
      route: initRoutes[0],
      isMatch: true,
    };
  }

  match?.route.view(mainContainer);
}

// document.addEventListener("DOMContentLoaded", () => {
//   router();
// });

export default router;
