// Generated by BUCKLESCRIPT VERSION 2.1.0, PLEASE EDIT WITH CARE
'use strict';

var React                    = require("react");
var ReasonReact              = require("reason-react/src/ReasonReact.js");
var Router$ReasonReactRouter = require("./Router.bs.js");

function text(prim) {
  return prim;
}

var component = ReasonReact.statelessComponent("App");

function make() {
  var newrecord = component.slice();
  newrecord[/* render */9] = (function () {
      return ReasonReact.element(/* None */0, /* None */0, Router$ReasonReactRouter.make((function (url) {
                        var match = url[/* path */0];
                        var tmp;
                        if (match) {
                          switch (match[0]) {
                            case "about" : 
                                tmp = match[1] ? "404 not found" : "ReasonReact Router - about page";
                                break;
                            case "posts" : 
                                var match$1 = match[1];
                                tmp = match$1 && !match$1[1] ? "Posts id #" + match$1[0] : "404 not found";
                                break;
                            default:
                              tmp = "404 not found";
                          }
                        } else {
                          tmp = "Home page";
                        }
                        return React.createElement("div", undefined, tmp);
                      })));
    });
  return newrecord;
}

exports.text      = text;
exports.component = component;
exports.make      = make;
/* component Not a pure module */
