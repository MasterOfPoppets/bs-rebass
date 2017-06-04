let optionMap fn option =>
  switch option {
  | Some value => Some (fn value)
  | None => None
  };

module Arrow = {
  type direction =
    | Up
    | Down;
  let directionToRebass direction =>
    switch direction {
    | Up => "up"
    | Down => "down"
    };
  external arrow : ReactRe.reactClass = "Arrow" [@@bs.module "rebass"];
  let createElement
      direction::(direction: option direction)=?
      style::(style: option ReactDOMRe.style)=? =>
    ReactRe.wrapPropsShamelessly
      arrow
      {
        "direction": Js.Null_undefined.from_opt (optionMap directionToRebass direction),
        "style": Js.Null_undefined.from_opt style
      };
};

module Button = {
  external button : ReactRe.reactClass = "Button" [@@bs.module "rebass"];
  let createElement
      href::(href: option string)=?
      big::(big: option bool)=?
      size::(size: option int)=?
      circle::(circle: option bool)=?
      ::baseRef=?
      onClick::(onClick: option (ReactEventRe.Form.t => unit))=?
      style::(style: option ReactDOMRe.style)=? =>
    ReactRe.wrapPropsShamelessly
      button
      {
        "href": Js.Null_undefined.from_opt href,
        "big": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean big),
        "size": Js.Null_undefined.from_opt size,
        "circle": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean circle),
        "baseRef": Js.Null_undefined.from_opt baseRef,
        "onClick": Js.Null_undefined.from_opt onClick,
        "style": Js.Null_undefined.from_opt style
      };
};

module Dropdown = {
  external dropdown : ReactRe.reactClass = "Dropdown" [@@bs.module];
  let createElement style::(style: option ReactDOMRe.style)=? =>
    ReactRe.wrapPropsShamelessly dropdown {"style": Js.Null_undefined.from_opt style};
};

module DropdownMenu = {
  external dropdownMenu : ReactRe.reactClass = "DropdownMenu" [@@bs.module];
  let createElement
      open_::(open_: option bool)=?
      right::(right: option bool)=?
      top::(top: option bool)=?
      onDismiss::(onDismiss: option (ReactEventRe.Form.t => unit))=?
      style::(style: option ReactDOMRe.style)=? =>
    ReactRe.wrapPropsShamelessly
      dropdownMenu
      {
        "open": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean open_),
        "right": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean right),
        "top": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean top),
        "onDismiss": Js.Null_undefined.from_opt onDismiss,
        "style": Js.Null_undefined.from_opt style
      };
};

module Heading = {
  type level =
    | H1
    | H2
    | H3
    | H4
    | H5
    | H6;
  type size =
    | Zero
    | One
    | Two
    | Three
    | Four
    | Five
    | Six;
  let levelToRebass level =>
    switch level {
    | H1 => 1
    | H2 => 2
    | H3 => 3
    | H4 => 4
    | H5 => 5
    | H6 => 6
    };
  let sizeToRebass size =>
    switch size {
    | Zero => 0
    | One => 1
    | Two => 2
    | Three => 3
    | Four => 4
    | Five => 5
    | Six => 6
    };
  external heading : ReactRe.reactClass = "Heading" [@@bs.module];
  let createElement
      big::(big: option bool)=?
      level::(level: option level)=?
      size::(size: option size)=?
      alt::(alt: option bool)=?
      center::(center: option bool)=?
      style::(style: option ReactDOMRe.style)=? =>
    ReactRe.wrapPropsShamelessly
      heading
      {
        "big": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean big),
        "level": Js.Null_undefined.from_opt (optionMap levelToRebass level),
        "size": Js.Null_undefined.from_opt (optionMap sizeToRebass size),
        "alt": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean alt),
        "center": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean center),
        "style": Js.Null_undefined.from_opt style
      };
};

module NavItem = {
  external navItem : ReactRe.reactClass = "NavItem" [@@bs.module];
  let createElement
      active::(active: option bool)=?
      small::(small: option bool)=?
      ::baseRef=?
      style::(style: option ReactDOMRe.style)=? =>
    ReactRe.wrapPropsShamelessly
      navItem
      {
        "active": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean active),
        "small": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean small),
        "baseRef": Js.Null_undefined.from_opt baseRef,
        "style": Js.Null_undefined.from_opt style
      };
};
