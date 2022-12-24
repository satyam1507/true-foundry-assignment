/* eslint-disable prettier/prettier */
import { Controller, Get, Res } from "@nestjs/common";
import { createReadStream } from "fs";
import { AppService } from "./app.service";
import { Response } from "express";

@Controller()
export class AppController {
    constructor(private readonly appService: AppService) {}

    @Get()
    getHtml(@Res() res: Response): void {
        const file = createReadStream(this.appService.getHtmlPath());
        file.pipe(res);
    }
}
