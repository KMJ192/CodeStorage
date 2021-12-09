import api from "../api";
import { productListUrl } from "../urls";
import { ProductListParam, ProductItemType } from "./types";
import { navigateTo } from "@src/router/router";

class ProductList {
  private mainContainer: Element;

  constructor(param: ProductListParam) {
    const { mainContainer } = param;
    this.mainContainer = mainContainer;
  }

  private listMaker(item: ProductItemType[]) {
    const ul = document.createElement("ul");
    const listTemplate = `
      <li class='Product' key={{key}} data-prod-id="{{product-id}}">
        <img src='{{imageURL}}'/>
        <div class='Product__info'>
          <div>{{name}}</div>
          <div>{{price}}원~</div>
        </div>
      </li>
    `;

    for (let i = 0; i < item.length; i++) {
      const { id, imageUrl, name, price } = item[i];
      let p = String(price);
      let tmp = [];
      let ptr = 0;

      for (let i = 1; i <= Math.floor(p.length / 3); i++) {
        tmp.push(p.substring(ptr, ptr + 3));
        ptr += 3;
      }
      p = tmp.join(",");

      let element = listTemplate.replace("{{key}}", `${String(id)}-name`);
      element = element.replace("{{product-id}}", String(id));
      element = element.replace("{{imageURL}}", imageUrl);
      element = element.replace("{{name}}", name);
      element = element.replace("{{price}}", p);

      ul.insertAdjacentHTML("beforeend", element);
    }

    return ul;
  }

  private productList() {
    const { mainContainer } = this;
    const prodListContainer = document.createElement("div");
    prodListContainer.className = "ProductListPage";

    const header = "<h1>상품목록</h2>";
    prodListContainer.innerHTML = header;

    let tmp = api("Get", productListUrl);
    if (tmp !== null) {
      tmp
        .then((item) => {
          prodListContainer.appendChild(this.listMaker(item));
          const li: HTMLCollectionOf<Element> =
            prodListContainer.getElementsByClassName("Product");
          for (let i = 0; i < li.length; i++) {
            (li[i] as HTMLLIElement).addEventListener(
              "click",
              this.productClickEvent
            );
          }
        })
        .catch((e) => console.error(e));
    }
    mainContainer.appendChild(prodListContainer);
  }

  async productClickEvent(e: MouseEvent) {
    const li = (e.target as Element).closest("li");
    const data: any = li?.dataset;
    const { prodId } = data;
    e.preventDefault();
    navigateTo(`/products/${prodId}`);
  }

  public render() {
    this.productList();
  }
}

export default ProductList;
