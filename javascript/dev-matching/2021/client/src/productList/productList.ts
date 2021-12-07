import api from "../api";
import { productListUrl } from "../urls";
import { ProductItemType } from "./types";
// import { RoutePath } from "../router/router";

const productClickEvent = (e: MouseEvent) => {
  console.log(e.currentTarget);
};

function listMaker(item: ProductItemType[]) {
  const ul = document.createElement("ul");
  const listTemplate = `
    <li class='Product'>
      <img src='{{imageURL}}'/>
      <div class='Product__info'>
        <div>{{name}}</div>
        <div>{{price}}원~</div>
      </div>
    </li>
  `;

  // const routePath = new RoutePath();

  for (let i = 0; i < item.length; i++) {
    const { id, imageUrl, name, price } = item[i];
    // routePath.setList(String(id));

    let p = String(price);
    let tmp = [];
    let ptr = 0;

    for (let i = 1; i <= Math.floor(p.length / 3); i++) {
      tmp.push(p.substring(ptr, ptr + 3));
      ptr += 3;
    }
    p = tmp.join(",");

    let element = listTemplate.replace("{{imageURL}}", imageUrl);
    element = element.replace("{{name}}", name);
    element = element.replace("{{price}}", p);

    ul.insertAdjacentHTML("beforeend", element);
  }

  return ul;
}

function productList(mainContainer: Element) {
  const prodListContainer = document.createElement("div");
  prodListContainer.className = "ProductListPage";

  const header = "<h1>상품목록</h2>";
  prodListContainer.innerHTML = header;

  let tmp = api("Get", productListUrl);
  if (tmp !== null) {
    tmp
      .then((item) => {
        prodListContainer.appendChild(listMaker(item));
        const li: HTMLCollectionOf<Element> =
          prodListContainer.getElementsByClassName("Product");
        for (let i = 0; i < li.length; i++) {
          (li[i] as HTMLLIElement).addEventListener("click", productClickEvent);
        }
      })
      .catch((e) => console.error(e));
  }
  mainContainer.appendChild(prodListContainer);
}

export default productList;
