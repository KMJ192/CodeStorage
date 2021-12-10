import ProductList from "../productList";
import ProductInfo from "../productInfo";
import ShoppingBack from "../shoppingBack";

import { ShoppingBackParam } from "../shoppingBack/types";
import { ProductInfoParam } from "../productInfo/types";
import { ProductListParam } from "../productList/types";

export interface Routes {
  path: string;
  view: (mainContainer: Element, id?: any) => void;
  queryString: boolean;
  param?: any;
}

export interface PageTypes {
  route: Routes;
  isMatch: boolean;
  param?: any;
}

export const routeInfo: Routes[] = [
  {
    path: "/",
    view: (mainContainer: Element) => {
      const param: ProductListParam = {
        mainContainer,
      };
      const productList = new ProductList(param);
      productList.render();
    },
    queryString: false,
  },
  {
    path: "products",
    view: (mainContainer: Element, id: any) => {
      const param: ProductInfoParam = {
        mainContainer,
        id: id.id,
      };
      const prodInfo = new ProductInfo(param);
      prodInfo.render();
    },
    queryString: true,
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
    queryString: false,
  },
];
