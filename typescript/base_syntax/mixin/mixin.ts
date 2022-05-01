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

class A {
  name: string;
  constructor() {
    this.name = "A";
  }
  display() {
    console.log(this.name);
  }
}

class B {
  name: string;
  constructor() {
    this.name = "Test2";
  }

  display() {
    console.log(this.name);
  }
}

class Rectangle implements Shape, A, Component, B {
  name: string;
  shape: string;
  component: string;

  w: number;
  h: number;
  constructor(w: number, h: number) {
    this.w = w;
    this.h = h;
    this.shape = "";
    this.component = "";
    this.name = "";
  }
  area(): number {
    return this.w * this.h;
  }

  display(): void {}
  draw(): void {}
  displayComponent(name: string): void {}
  displayShape(name: string): void {}
}

class Render {
  render() {
    mixin(Rectangle, [Shape, Component, A, B]);
    let rectangle = new Rectangle(4, 3);
    rectangle.draw();
    rectangle.displayComponent("component");
    rectangle.displayShape("shape");
    rectangle.display();
  }
}

export default function mixinTest() {
  const render = new Render();
  render.render();
}
