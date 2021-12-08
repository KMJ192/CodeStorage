import { ShoppingBackParam } from "./types";

class ShoppingBack {
  mainContainer: Element;
  constructor(param: ShoppingBackParam) {
    const { mainContainer } = param;
    this.mainContainer = mainContainer;
  }

  render() {
    const header = `<h1>장바구니</h1>`;
    const shoppingBackContainer = document.createElement("div");
    shoppingBackContainer.innerHTML = header;
    this.mainContainer.appendChild(shoppingBackContainer);
  }
}
export default ShoppingBack;
