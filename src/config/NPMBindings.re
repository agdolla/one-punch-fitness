module RNCalendars = {
  module Calendar = {
    [@bs.module "react-native-calendars"]
    external calendar : ReasonReact.reactClass = "Calendar";
    let make =
        (
          ~minDate: option(string)=?,
          ~onDayPress: option(Js.t({..}) => unit)=?,
          ~hideArrows: option(Js.boolean)=?,
          ~monthFormat: option(string)=?,
          ~current: option(string)=?,
          ~onMonthChange: option(string => unit)=?,
          ~hideExtraDays: option(Js.boolean)=?,
          ~disableMonthChange: option(Js.boolean)=?,
          ~firstDay: option(int)=?,
          ~hideDayNames: option(Js.boolean)=?,
          ~markedDates:
             Js.Dict.t(
               {
                 .
                 "startingDay": Js.boolean,
                 "endingDay": Js.boolean,
                 "color": string,
                 "textColor": string
               }
             ),
          ~style: option(BsReactNative.Style.t)=?,
          ~markingType: option(string)=?,
          children
        ) =>
      ReasonReact.wrapJsForReason(
        ~reactClass=calendar,
        ~props={
          "minDate": Js.Nullable.from_opt(minDate),
          "current": Js.Nullable.from_opt(current),
          "onDayPress": Js.Nullable.from_opt(onDayPress),
          "hideArrows": Js.Nullable.from_opt(hideArrows),
          "monthFormat": Js.Nullable.from_opt(monthFormat),
          "onMonthChange": Js.Nullable.from_opt(onMonthChange),
          "hideExtraDays": Js.Nullable.from_opt(hideExtraDays),
          "disableMonthChange": Js.Nullable.from_opt(disableMonthChange),
          "firstDay": Js.Nullable.from_opt(firstDay),
          "hideDayNames": Js.Nullable.from_opt(hideDayNames),
          "markedDates": markedDates,
          "markingType": Js.Nullable.from_opt(markingType),
          "style": Js.Nullable.from_opt(style)
        },
        children
      );
  };
};

module Expo = {
  module Font = {
    [@bs.scope "Font"] [@bs.module "expo"]
    external loadAsync : Js.t({..}) => Js.Promise.t(unit) = "loadAsync";
  };
  module AppLoading = {
    [@bs.module "expo"]
    external appLoading : ReasonReact.reactClass = "AppLoading";
    let make = children =>
      ReasonReact.wrapJsForReason(
        ~reactClass=appLoading,
        ~props=Js.Obj.empty(),
        children
      );
  };
  module Permissions = {
    [@bs.scope "Permissions"] [@bs.module "expo"]
    external notifications : string = "NOTIFICATIONS";
    [@bs.scope "Permissions"] [@bs.module "expo"]
    external ask :
      string =>
      Js.Promise.t(
        {
          .
          "expires": string,
          "status": string
        }
      ) =
      "askAsync";
    [@bs.scope "Permissions"] [@bs.module "expo"]
    external get :
      string =>
      Js.Promise.t(
        {
          .
          "expires": string,
          "status": string
        }
      ) =
      "getAsync";
  };
  module Notifications = {
    type localNotification = {
      .
      "title": string,
      "body": string
    };
    type schedulingOptions = {
      .
      "time": float,
      "repeat": string
    };
    [@bs.scope "Notifications"] [@bs.module "expo"]
    external scheduleLocalNotificationAsync :
      (localNotification, schedulingOptions) => Js.Promise.t(string) =
      "scheduleLocalNotificationAsync";
    [@bs.scope "Notifications"] [@bs.module "expo"]
    external cancelAllScheduledNotifications : unit => unit =
      "cancelAllScheduledNotificationsAsync";
    [@bs.scope "Notifications"] [@bs.module "expo"]
    external cancelAllScheduledNotificationsAsync : unit => Js.Promise.t(unit) =
      "cancelAllScheduledNotificationsAsync";
  };
  module KeepAwake = {
    [@bs.module "expo"]
    external keepAwake : ReasonReact.reactClass = "KeepAwake";
    let make = children =>
      ReasonReact.wrapJsForReason(
        ~reactClass=keepAwake,
        ~props=Js.Obj.empty(),
        children
      );
  };
  module Util = {
    [@bs.scope "Util"] [@bs.module "expo"]
    external reload : unit => unit = "reload";
  };
};

module VectorIcons = {
  module Feather = {
    [@bs.module "@expo/vector-icons"]
    external feather : ReasonReact.reactClass = "Feather";
    let make = (~name: string, ~size: int, ~color: string, children) =>
      ReasonReact.wrapJsForReason(
        ~reactClass=feather,
        ~props={"name": name, "size": size, "color": color},
        children
      );
  };
};

module DateTimePicker = {
  [@bs.module "react-native-modal-datetime-picker"]
  external dateTimePicker : ReasonReact.reactClass = "default";
  let make =
      (
        ~isVisible: bool=false,
        ~onConfirm: option(Js.Date.t => unit)=?,
        ~onCancel: option(unit => unit)=?,
        ~mode: option(string)=?,
        ~titleIOS: option(string)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=dateTimePicker,
      ~props={
        "isVisible": Js.Boolean.to_js_boolean(isVisible),
        "onConfirm": Js.Nullable.from_opt(onConfirm),
        "onCancel": Js.Nullable.from_opt(onCancel),
        "titleIOS": Js.Nullable.from_opt(titleIOS),
        "mode": Js.Nullable.from_opt(mode)
      },
      children
    );
};

module Moment = {
  [@bs.module] external make : string => Js.t({..}) = "moment";
};

module Chroma = {
  [@bs.module "chroma-js"]
  external scale :
    Js.Array.t(string) =>
    {
      .
      [@bs.meth]
      "mode": string => {. [@bs.meth] "colors": int => Js.Array.t(string)}
    } =
    "scale";
  [@bs.module "chroma-js"]
  external make : string => {. [@bs.meth] "luminance": unit => float} =
    "default";
};

module RNTicker = {
  [@bs.module "react-native-ticker"]
  external js : ReasonReact.reactClass = "default";
  let make =
      (~text: string, ~textStyle: option(BsReactNative.Style.t)=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=js,
      ~props={"text": text, "textStyle": Js.Nullable.from_opt(textStyle)},
      children
    );
};