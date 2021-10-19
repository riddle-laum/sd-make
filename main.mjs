// ----- main.js ----- //
// automatic generated by sd-make.exe made by laum-riddle

// namespace
const savedojin = {};

// constant
savedojin.version = '2.0.0+10'

// ----- main ----- //
savedojin.main = async ()=>{
  // show info
  console.log('[savedojin]', 'savedojin :', savedojin.version);

  // get website domain
  const domain = location.hostname;
  console.log('[savedojin]', 'website :', domain);
  
  // call module
  if(savedojin.modules[domain]) await savedojin.deploy(await savedojin.modules[domain].main());
  else console.warn('[savedojin]', `"${domain}" is not supported`), alert(`[savedojin] "${domain}" is not supported`);
};

// ----- deploy ----- //
savedojin.deploy = async ({urls, title})=>{
  if(!(urls instanceof Array) || !urls.length) throw new Error('invalid value in "urls"');
  let dom = document.createElement('html');
  dom.appendChild(document.createElement('head'));
  dom.appendChild(document.createElement('body'));
  dom.querySelector('head').appendChild(document.createElement('meta'));
  dom.querySelector('meta').setAttribute('charset', 'utf-8');
  dom.querySelector('body').appendChild(document.createElement('div'));
  dom.querySelector('div').setAttribute('id', 'main-contents');
  for(const url of urls){
    const img = document.createElement('img');
    img.setAttribute('src', url);
    img.setAttribute('style', 'width:100%;');
    dom.querySelector('div').appendChild(img);
  }
  document.querySelector('html').remove();
  document.appendChild(dom);
  if(typeof(title) == 'string') document.title = title;
};

savedojin.modules = {
  'buhidoh.net': {
    main: ()=>{
      const r =  {urls:[],title:''};
      if(document.querySelectorAll('.ently_text > a').length)
        for(var dom of document.querySelectorAll('.ently_text > a')) r.urls.push(dom.href);
      else for(var dom of document.querySelectorAll('.ently_text > p > a')) r.urls.push(dom.href);
      r.title = 'buhidoh-' + location.href.split(/\/|\./g)[4];
      return r;
    }
  },
  'daretoku-eromanga.info': {
    main: ()=>{
      const r = {urls:[],title:''};
      var locate;
      for(var dom of document.querySelectorAll('.article a')) r.urls.push(dom.href);
      r.title = 'daretoku-eromanga-' + (locate = location.href.split('/'))[locate.length - 1];
      return r;
    }
  },
};

// ----- when clicked ----- //
savedojin.main()
