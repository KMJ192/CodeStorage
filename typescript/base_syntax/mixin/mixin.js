"use strict";
exports.__esModule = true;
function mixin(targetClass, baseClasses) {
    baseClasses.forEach(function (baseClass) {
        Object.getOwnPropertyNames(baseClass.prototype).forEach(function (name) {
            var descriper = Object.getOwnPropertyDescriptor(baseClass.prototype, name);
            if (descriper) {
                Object.defineProperty(targetClass.prototype, name, descriper);
            }
        });
    });
}
var Shape = /** @class */ (function () {
    function Shape() {
        this.shape = "";
    }
    Shape.prototype.draw = function () {
        console.log("shapis drawing");
    };
    Shape.prototype.displayShape = function (name) {
        this.shape = name;
        console.log(this.shape);
    };
    return Shape;
}());
var Component = /** @class */ (function () {
    function Component() {
        this.component = "";
    }
    Component.prototype.display = function () {
        console.log("component is displaying");
    };
    Component.prototype.displayComponent = function (name) {
        this.component = name;
        console.log(this.component);
    };
    return Component;
}());
var A = /** @class */ (function () {
    function A() {
        this.name = "A";
    }
    A.prototype.display = function () {
        console.log(this.name);
    };
    return A;
}());
var B = /** @class */ (function () {
    function B() {
        this.name = "Test2";
    }
    B.prototype.display = function () {
        console.log(this.name);
    };
    return B;
}());
var Rectangle = /** @class */ (function () {
    function Rectangle(w, h) {
        this.w = w;
        this.h = h;
        this.shape = "";
        this.component = "";
        this.name = "";
    }
    Rectangle.prototype.area = function () {
        return this.w * this.h;
    };
    Rectangle.prototype.display = function () { };
    Rectangle.prototype.draw = function () { };
    Rectangle.prototype.displayComponent = function (name) { };
    Rectangle.prototype.displayShape = function (name) { };
    return Rectangle;
}());
var Render = /** @class */ (function () {
    function Render() {
    }
    Render.prototype.render = function () {
        mixin(Rectangle, [Shape, Component, A, B]);
        var rectangle = new Rectangle(4, 3);
        rectangle.draw();
        rectangle.displayComponent("component");
        rectangle.displayShape("shape");
        rectangle.display();
    };
    return Render;
}());
function mixinTest() {
    var render = new Render();
    render.render();
}
exports["default"] = mixinTest;
