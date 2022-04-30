function mixin(targetClass: any, baseClasses: any) {
  baseClasses.forEach((baseClass: any) => {
    Object.getOwnPropertyNames(baseClass.prototype).forEach((name) => {
      const descriper = Object.getOwnPropertyDescriptor(
        baseClass.prototype,
        name
      );
      if (descriper) {
        Object.defineProperty(targetClass.prototype, name, descriper);
      }
    });
  });
}

class Shape {
  shape: string;
  constructor() {
    this.shape = "";
  }
  draw(): void {
    console.log("shapis drawing");
  }
  displayShape(name: string) {
    this.shape = name;
    console.log(this.shape);
  }
}

class Component {
  component: string;
  constructor() {
    this.component = "";
  }

  display(): void {
    console.log("component is displaying");
  }
  displayComponent(name: string) {
    this.component = name;
    console.log(this.component);
  }
}

class Rectangle implements Shape, Component {
  shape: string;
  component: string;

  w: number;
  h: number;
  constructor(w: number, h: number) {
    this.w = w;
    this.h = h;
    this.shape = "";
    this.component = "";
  }
  area(): number {
    return this.w * this.h;
  }

  display(): void {}
  draw(): void {}
  displayComponent(name: string): void {}
  displayShape(name: string): void {}
}

export default function mixinTest() {
  mixin(Rectangle, [Shape, Component]);

  let rectangle = new Rectangle(4, 3);
  rectangle.draw();
  rectangle.display();
  rectangle.displayComponent("component");
  rectangle.displayShape("shape");
}
