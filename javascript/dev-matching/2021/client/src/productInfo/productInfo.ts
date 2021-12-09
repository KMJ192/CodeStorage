import { ProductInfoParam } from "./types";

class ProductInfo {
  mainContainer: Element;
  id: number;
  constructor(param: ProductInfoParam) {
    const { mainContainer } = param;
    this.mainContainer = mainContainer;
    this.id = -1;
  }

  render() {
    const header = `<h1>상품정보</h1>`;
    const shoppingBackContainer = document.createElement("div");
    shoppingBackContainer.innerHTML = header;
    this.mainContainer.appendChild(shoppingBackContainer);
  }
}
export default ProductInfo;
