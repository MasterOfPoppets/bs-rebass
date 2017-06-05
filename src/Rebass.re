let optionMap fn option =>
  switch option {
  | Some value => Some (fn value)
  | None => None
  };

let wrapRebassPropsShamelessly
    reactClass
    props
    style::(style: option ReactDOMRe.style)=?
    onClick::(onClick: option (ReactEventRe.Form.t => unit))=? =>
  ReactRe.wrapPropsShamelessly
    reactClass
    (
      Js.Obj.assign
        {"style": Js.Null_undefined.from_opt style, "onClick": Js.Null_undefined.from_opt onClick}
        props
    );

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
  let createElement direction::(direction: option direction)=? =>
    wrapRebassPropsShamelessly
      arrow {"direction": Js.Null_undefined.from_opt (optionMap directionToRebass direction)};
};

module AspectRatio = {
  external aspectRatio : ReactRe.reactClass = "AspectRatio" [@@bs.module "rebass"];
  let createElement = wrapRebassPropsShamelessly aspectRatio (Js.Obj.empty ());
};

module Avatar = {
  external avatar : ReactRe.reactClass = "Avatar" [@@bs.module "rebass"];
  let createElement size::(size: option int)=? =>
    wrapRebassPropsShamelessly avatar {"size": Js.Null_undefined.from_opt size};
};

module Badge = {
  external badge : ReactRe.reactClass = "Badge" [@@bs.module "rebass"];
  let createElement = wrapRebassPropsShamelessly badge (Js.Obj.empty ());
};

module Banner = {
  type align =
    | Left
    | Center
    | Right;
  let alignToRebass align =>
    switch align {
    | Left => "left"
    | Center => "center"
    | Right => "right"
    };
  external banner : ReactRe.reactClass = "Banner" [@@bs.module "rebass"];
  let createElement
      align::(align: option align)=?
      backgroundImage::(backgroundImage: option string)=? =>
    wrapRebassPropsShamelessly
      banner
      {
        "align": Js.Null_undefined.from_opt (optionMap alignToRebass align),
        "backgroundImage": Js.Null_undefined.from_opt backgroundImage
      };
};

module Bar = {
  external bar : ReactRe.reactClass = "Bar" [@@bs.module "rebass"];
  let createElement = wrapRebassPropsShamelessly bar (Js.Obj.empty ());
};

module Block = {
  external block : ReactRe.reactClass = "Block" [@@bs.module "rebass"];
  let createElement
      borderColor::(borderColor: option string)=?
      border::(border: option bool)=?
      borderTop::(borderTop: option bool)=?
      borderRight::(borderRight: option bool)=?
      borderBottom::(borderBottom: option bool)=?
      borderLeft::(borderLeft: option bool)=? =>
    wrapRebassPropsShamelessly
      block
      {
        "borderColor": Js.Null_undefined.from_opt borderColor,
        "border": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean border),
        "borderTop": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean borderTop),
        "borderRight": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean borderRight),
        "borderBottom":
          Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean borderBottom),
        "borderLeft": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean borderLeft)
      };
};

module Blockquote = {
  external blockquote : ReactRe.reactClass = "Blockquote" [@@bs.module "rebass"];
  let createElement source::(source: option string)=? href::(href: option string)=? =>
    wrapRebassPropsShamelessly
      blockquote
      {"source": Js.Null_undefined.from_opt source, "href": Js.Null_undefined.from_opt href};
};

module BoxShadow = {
  external boxShadow : ReactRe.reactClass = "BoxShadow" [@@bs.module "rebass"];
  let createElement = wrapRebassPropsShamelessly boxShadow (Js.Obj.empty ());
};

module Breadcrumbs = {
  type link = {children: string, href: string};
  let makeLink link => {"children": link.children, "href": link.href};
  external breadcrumbs : ReactRe.reactClass = "Breadcrumbs" [@@bs.module "rebass"];
  let createElement links::(links: array link) =>
    wrapRebassPropsShamelessly breadcrumbs {"links": Array.map makeLink links};
};

module Button = {
  external button : ReactRe.reactClass = "Button" [@@bs.module "rebass"];
  let createElement
      href::(href: option string)=?
      big::(big: option bool)=?
      size::(size: option int)=?
      circle::(circle: option bool)=?
      ::baseRef=? =>
    wrapRebassPropsShamelessly
      button
      {
        "href": Js.Null_undefined.from_opt href,
        "big": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean big),
        "size": Js.Null_undefined.from_opt size,
        "circle": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean circle),
        "baseRef": Js.Null_undefined.from_opt baseRef
      };
};

module Dropdown = {
  external dropdown : ReactRe.reactClass = "Dropdown" [@@bs.module "rebass"];
  let createElement = wrapRebassPropsShamelessly dropdown (Js.Obj.empty ());
};

module DropdownMenu = {
  external dropdownMenu : ReactRe.reactClass = "DropdownMenu" [@@bs.module "rebass"];
  let createElement
      open_::(open_: option bool)=?
      right::(right: option bool)=?
      top::(top: option bool)=?
      onDismiss::(onDismiss: option (ReactEventRe.Form.t => unit))=? =>
    wrapRebassPropsShamelessly
      dropdownMenu
      {
        "open": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean open_),
        "right": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean right),
        "top": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean top),
        "onDismiss": Js.Null_undefined.from_opt onDismiss
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
  external heading : ReactRe.reactClass = "Heading" [@@bs.module "rebass"];
  let createElement
      big::(big: option bool)=?
      level::(level: option level)=?
      size::(size: option size)=?
      alt::(alt: option bool)=?
      center::(center: option bool)=? =>
    wrapRebassPropsShamelessly
      heading
      {
        "big": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean big),
        "level": Js.Null_undefined.from_opt (optionMap levelToRebass level),
        "size": Js.Null_undefined.from_opt (optionMap sizeToRebass size),
        "alt": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean alt),
        "center": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean center)
      };
};

module Input = {
  external input : ReactRe.reactClass = "Input" [@@bs.module "rebass"];
  let createElement
      label::(label: string)
      name::(name: string)
      type_::(type_: option string)=?
      message::(message: option string)=?
      hideLabel::(hideLabel: option bool)=?
      horizontal::(horizontal: option bool)=?
      autoOff::(autoOff: option bool)=?
      ::baseRef=?
      value::(value: option string)=?
      ::onChange=? =>
    wrapRebassPropsShamelessly
      input
      {
        "label": label,
        "name": name,
        "type": Js.Null_undefined.from_opt type_,
        "message": Js.Null_undefined.from_opt message,
        "hideLabel": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean hideLabel),
        "horizontal": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean horizontal),
        "autoOff": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean autoOff),
        "baseRef": Js.Null_undefined.from_opt baseRef,
        "value": Js.Null_undefined.from_opt value,
        "onChange": Js.Null_undefined.from_opt onChange
      };
};

module NavItem = {
  external navItem : ReactRe.reactClass = "NavItem" [@@bs.module "rebass"];
  let createElement active::(active: option bool)=? small::(small: option bool)=? ::baseRef=? =>
    wrapRebassPropsShamelessly
      navItem
      {
        "active": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean active),
        "small": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean small),
        "baseRef": Js.Null_undefined.from_opt baseRef
      };
};
