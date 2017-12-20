// Generated by BUCKLESCRIPT VERSION 2.1.0, PLEASE EDIT WITH CARE
"use strict";

var InfoCard = require("./components/InfoCard/InfoCard.bs.js");
var Js_boolean = require("bs-platform/lib/js/js_boolean.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var WorkoutCard = require("./components/WorkoutCard/WorkoutCard.bs.js");
var Style$BsReactNative = require("bs-react-native/src/style.js");
var Container = require("./components/styled/Container");
var SectionLabel = require("./components/styled/SectionLabel");

function make(
  contentContainerStyle,
  alwaysBounceVertical,
  showsVerticalScrollIndicator,
  children
) {
  return ReasonReact.wrapJsForReason(
    Container.default,
    {
      contentContainerStyle: contentContainerStyle,
      alwaysBounceVertical: Js_boolean.to_js_boolean(alwaysBounceVertical),
      showsVerticalScrollIndicator: Js_boolean.to_js_boolean(
        showsVerticalScrollIndicator
      ),
    },
    children
  );
}

var Container$1 = /* module */ [/* make */ make];

function make$1(children) {
  return ReasonReact.wrapJsForReason(SectionLabel.default, {}, children);
}

var SectionLabel$1 = /* module */ [/* make */ make$1];

var Styled = /* module */ [
  /* Container */ Container$1,
  /* SectionLabel */ SectionLabel$1,
];

var component = ReasonReact.statelessComponent("CalendarScreen");

function make$2(screenProps, _) {
  var newrecord = component.slice();
  newrecord[/* render */ 9] = function() {
    return ReasonReact.element(
      /* None */ 0,
      /* None */ 0,
      make(
        Style$BsReactNative.style(
          /* :: */ [Style$BsReactNative.flexGrow(1), /* [] */ 0]
        ),
        /* false */ 0,
        /* false */ 0,
        /* array */ [
          ReasonReact.element(
            /* None */ 0,
            /* None */ 0,
            WorkoutCard.make(screenProps.rootNavigation, /* array */ [])
          ),
          ReasonReact.element(
            /* None */ 0,
            /* None */ 0,
            make$1(/* array */ ["GOODIES"])
          ),
          ReasonReact.element(
            /* None */ 0,
            /* None */ 0,
            InfoCard.make(
              screenProps.rootNavigation,
              "inspiration",
              "Learn about this routine from Saitama himself!",
              /* array */ []
            )
          ),
        ]
      )
    );
  };
  return newrecord;
}

var $$default = ReasonReact.wrapReasonForJs(component, function(jsProps) {
  return make$2(jsProps.screenProps, /* array */ []);
});

exports.Styled = Styled;
exports.component = component;
exports.make = make$2;
exports.$$default = $$default;
exports.default = $$default;
exports.__esModule = true;
/* component Not a pure module */