open Discord;

[@bs.module "process"] external platform: string = "platform";
[@bs.module "os"] external releaseF: unit => string = "release";

let secondsPerDay = 86400;
[@bs.module "os"] external uptimeF: unit => int = "uptime";

let bytesPerGB = 1073741824;
[@bs.module "os"] external totalmemF: unit => int = "totalmem";
[@bs.module "os"] external freememF: unit => int = "freemem";

// I'm not sure if bucklescript can execute these functions automatically via the externals 🤔
let release = releaseF();
let uptime = uptimeF() / secondsPerDay;
let totalmem = totalmemF() / bytesPerGB;
let freemem = freememF() / bytesPerGB;


// storage will need bindings to https://systeminformation.io
let info = {j|
OS codename: $platform version $release
Uptime: $uptime days
Memory: $freemem / $totalmem GB
Storage: plenty 😂
|j}

// Js.log2("sys info", info);

let richInfo = () => {
  open RichEmbed;
  create()
  ->title("Spyder's bot hosting system")
  ->color("DARK_PURPLE")
  ->description(info);
};