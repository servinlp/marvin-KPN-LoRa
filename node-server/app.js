const express = require( 'express' ),
	app = express(),
	ejs = require( 'ejs' ),
	bodyParser = require( 'body-parser' ),
	BigNumber = require( 'bignumber.js' ),
	obj = [],
	PORT = 8000

app.use( bodyParser.urlencoded({ extended: false }) )
app.use( bodyParser.json() )

app.set( 'view engine', 'ejs' )
app.set( 'views', './views' )

app.get( '/', ( req, res ) => {

	res.render( 'index', { messages: obj })

})

app.post( '/entries', ( req, res ) => {

	let hex = req.body.DevEUI_uplink.payload_hex,
		x = new BigNumber( hex, 16 )

	if ( x.isInt() && x.gte(0) ) {
		
		if ( hex.length === 2 && x.gte( 128 ) ) x = x.minus( 256 )
		if ( hex.length === 4 && x.gte( 32768 ) ) x = x.minus( 65536 )
		if ( hex.length === 8 && x.gte( 2147483648 ) ) x = x.minus( 4294967296 )
		if ( hex.length === 16 && x.gte( 9223372036854775808 ) ) x = x.minus( 18446744073709551616 )
		if ( hex.length === 2 || hex.length === 4 || hex.length === 8 || hex.length === 16 ) {
			
			x = x.toString(10)
			
		} else {
			
			x = "N/A"
			
		}
			
	} else {
		
		x = "N/A"
		
	}

	obj.push( x )

	res.writeHead( 200, { 'Content-Type': 'application/json' })

	const json = JSON.stringify({
		succes: true
	})

	res.end( json )

})

app.listen( PORT, () => {

	console.log( `Hello from ${PORT}` )

})
