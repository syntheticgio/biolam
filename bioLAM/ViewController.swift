//
//  ViewController.swift
//  bioLAM
//
//  Created by Jonny on 2/28/17.
//  Copyright © 2017 Mazumder Lab. All rights reserved.
//

import Cocoa

class ViewController: NSViewController {

    @IBOutlet weak var upload_new_file_option: NSButton!
    @IBOutlet weak var download_from_url: NSButton!
    @IBOutlet weak var enterText: NSStackView!
    @IBOutlet weak var longName: NSTextField!
    @IBOutlet weak var itext: NSTextField!
    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
    }

    override var representedObject: Any? {
        didSet {
        // Update the view, if already loaded.
        }
    }

    @IBAction func changeText(_ sender: Any) {
        longName.stringValue = "\(itext.stringValue)"
        let file_picker: NSOpenPanel = NSOpenPanel()
        
        //Set up parameters
        file_picker.canChooseFiles = true
        file_picker.canChooseDirectories = false
        file_picker.allowsMultipleSelection = false
        
        file_picker.runModal()
        let chosenFile = file_picker.url
        if(chosenFile != nil) {
            longName.stringValue = "\(file_picker.url!)"
        }
        //file_picker.url! is the file path, how to open it into a file?
        //let file = file_picker.url! //this is the file. we will write to and read from it
        let file:String = file_picker.url!.path
        //let text = "some text" //just a text
        do {
            let data = try String(contentsOfFile: file, encoding: .utf8)
            print ("Data : \(data)")
        } catch {
            print("Error")
        }
        

//        if let dir = FileManager.default.urls(for: .documentDirectory, in: .userDomainMask).first {
//            let path = dir.appendingPathComponent(path)
//            print("Path: \(path)")
//            
//            //reading
//            do {
//                let text2 = try String(contentsOf: path, encoding: String.Encoding.utf8)
//            }
//            catch {/* error handling here */}
//            
            //writing
//            do {
//                tr
//                try text.write(to: path, atomically: false, encoding: String.Encoding.utf8)
//            }
//            catch {/* error handling here */}
//            
//            //reading
//            do {
//                let text2 = try String(contentsOf: path, encoding: String.Encoding.utf8)
//            }
//            catch {/* error handling here */}
        }
    }
    
    func radioButtonChanged(_ sender: AnyObject) {
        
    }



