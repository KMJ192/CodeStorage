import api from "../api";
import { productInfoUrl } from "../urls";
import { ProductInfoParam } from "./types";

class ProductInfo {
  mainContainer: Element;
  id: number;
  apiUrl: string;
  constructor(param: ProductInfoParam) {
    const { mainContainer, id } = param;
    this.mainContainer = mainContainer;
    this.id = id || 1;
    this.apiUrl = productInfoUrl.replace("<id>", String(this.id));
  }

  private productInfo() {
    const tmp = api("Get", this.apiUrl);
    if (tmp !== null) {
      tmp.then((data) => {
        console.log(data);
      });
    }
  }

  public render() {
    const header = `<h1>상품정보</h1>`;
    this.mainContainer.innerHTML = header;
  }
}
export default ProductInfo;
