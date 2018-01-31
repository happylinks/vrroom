// Generated by BUCKLESCRIPT VERSION 2.1.0, PLEASE EDIT WITH CARE
'use strict';

var Curry       = require("bs-platform/lib/js/curry.js");
var React       = require("react");
var Vrroom      = require("../src/Vrroom.bs.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");

var maybeErrorClass = /* Some */["is-oops"];

var instance = ReasonReact.statelessComponent("ClassName example");

function make() {
  var newrecord = instance.slice();
  newrecord[/* render */9] = (function () {
      var className = Curry._1(Vrroom.Helpers[/* ClassName */5][/* join */0], /* :: */[
            "tooltip",
            /* :: */[
              Curry._2(Vrroom.Helpers[/* ClassName */5][/* if_ */1], /* true */1, "s-hovered"),
              /* :: */[
                Curry._1(Vrroom.Helpers[/* ClassName */5][/* fromOption */2], maybeErrorClass),
                /* [] */0
              ]
            ]
          ]);
      return React.createElement("div", undefined, React.createElement("div", {
                      className: className
                    }, Vrroom.text("Hello world!")), React.createElement("div", {
                      className: Curry._1(Vrroom.Helpers[/* ClassName */5][/* join */0], /* :: */[
                            "tooltip",
                            /* :: */[
                              Curry._2(Vrroom.Helpers[/* ClassName */5][/* if_ */1], /* true */1, "s-hovered"),
                              /* [] */0
                            ]
                          ])
                    }, Vrroom.text("Hello world!")));
    });
  return newrecord;
}

var isHovered = /* true */1;

exports.maybeErrorClass = maybeErrorClass;
exports.isHovered       = isHovered;
exports.instance        = instance;
exports.make            = make;
/* instance Not a pure module */
